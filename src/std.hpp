/**
 * 
 * 
 *   @author Sean Hobeck
 * 
 *    @date 02/12/2023
 * 
 * 
 **/
#pragma once

/// @uses: scekernel functions
#include "bits.hpp"

/// @uses: std::unique_ptr, std types
#include <memory>

/// @uses: cstdio, std::string, std::wstring
#include <string>


/// @brief vita cplusplus port namespace
namespace vcp3
{
    /// ------------------------- @section System Calls -------------------- ///

    /// @brief Exit the current process.
    /// @param e Error number.
    /// @return the Error code.
    static std::int32_t 
    exit(std::int32_t e = 0) 
    { 
        return (std::int32_t) sceKernelExitProcess(e); 
    };

    /// @brief Printing out to the console with a std::string.
    /// @tparam pargs_t Packed arguments.
    /// @param __format String to be formatted.
    /// @param args Format arguments.
    template <typename ... pargs_t>
    static void
    printf(const std::string& __format, pargs_t... args)
    {
        fprintf(stdout, __format.c_str(), args...);
    };

    /// @brief Printing out to the console with a std::wstring.
    /// @tparam pargs_t Packed arguments.
    /// @param __format Wide string to be formatted.
    /// @param args Format arguments.
    template <typename ... pargs_t>
    static void
    wprintf(const std::wstring& __format, pargs_t... args)
    {
        fwprintf(stdout, __format.c_str(), args...);
    };

    /// @brief Formatting a string to a output buffer.
    /// @tparam pargs_t Packed arguments.
    /// @param __format String to be formatted.
    /// @param args Format arguments
    /// @return Reference to output buffer.
    template <typename ... pargs_t>
    static std::string&
    sprintf(const std::string& __format, pargs_t... args) 
    {
        char* buffer;
        sprintf(buffer, __format.c_str(), args...);
        std::string __buf = std::string(buffer);
        return __buf;
    };

    /// @brief Formatting a wstring to a output buffer.
    /// @tparam pargs_t Packed arguments.
    /// @param __format Wide string to be formatted.
    /// @param args Format arguments
    /// @return Reference to output buffer.
    template <typename ... pargs_t>
    static std::wstring&
    swprintf(const std::wstring& __format, pargs_t... args) 
    {
        wchar_t* buffer;
        swprintf(buffer, __format.c_str(), args...);
        std::wstring __buf = std::wstring(buffer);
        return __buf;
    };

    /// @brief Formatting a string to a output buffer (with N number of bytes).
    /// @tparam pargs_t Packed arguments.
    /// @param __format String to be formatted.
    /// @param __n Number of bytes.
    /// @param args Format arguments
    /// @return Reference to output buffer.
    template <typename ... pargs_t>
    static std::string&
    snprintf(const std::string& __format, const std::size_t __n, pargs_t... args) 
    {
        char* buffer;
        snprintf(buffer, __n, __format.c_str(), args...);
        std::string __buf = std::string(buffer);
        return __buf;
    };

    /// @brief Writing data to a file.
    /// @param __file File to be written.
    /// @param __buf std::string buffer to be written.
    static void
    fwrite(const std::string& __file, const std::string& __buf) 
    {
        if (std::size_t __fd = sceIoOpen(__file.c_str(), SCE_O_WRONLY|SCE_O_CREAT, 777)) {
            sceIoWrite(__fd, (const void*) __buf.data(), (std::size_t) __buf.length());
            sceIoClose(__fd);
        }
    };

    /// @brief Writing data to a file.
    /// @tparam T The type buffer.
    /// @param __fd File to be written.
    /// @param __buf the tparam buffer. 
    template<typename T>
    static void
    fwrite(const std::string& __file, const T& __buf) 
    {
        if (std::size_t __fd = sceIoOpen(__file.c_str(), SCE_O_WRONLY|SCE_O_CREAT, 777)) {
            sceIoWrite(__fd, (const void*) __buf, (std::size_t) sizeof(T));
            sceIoClose(__fd);
        }
    };

    /// @brief Writing data to a file.
    /// @tparam T The type buffer.
    /// @param __fd File to be written.
    /// @param __buf the tparam buffer. 
    template<typename T>
    static void
    fwritep(const std::string& __file, const T& __buf, const std::int64_t __o) 
    {
        if (std::size_t __fd = sceIoOpen(__file.c_str(), SCE_O_WRONLY|SCE_O_CREAT, 777)) {
            sceIoPwrite(__fd, (const void*) __buf, (std::size_t) sizeof(T), __o);
            sceIoClose(__fd);
        }
    };

    /// @brief Reading data from a file.
    /// @param __file File to read.
    /// @param __n Number of bytes.
    /// @return Bytes read.
    static const void*
    fread(const std::string& __file, const std::size_t __n) {
        if (std::size_t __fd = sceIoOpen(__file.c_str(), SCE_O_WRONLY|SCE_O_CREAT, 777)) {
            void* __buf;
            sceIoRead(__fd, __buf, __n);
            sceIoClose(__fd);
            return __buf;
        }
    };

    /// @brief Reading data from a file.
    /// @param __file File to read.
    /// @param __n Number of bytes (default sizeof[T])
    /// @tparam T Class to be casted to.
    /// @return T type of bytes casted.
    template<typename T>
    static const T
    fread(const std::string& __file, const std::size_t __n = sizeof(T)) {
        if (std::size_t __fd = sceIoOpen(__file.c_str(), SCE_O_WRONLY|SCE_O_CREAT, 777)) {
            void* __buf;
            sceIoRead(__fd, __buf, __n);
            sceIoClose(__fd);
            return (T) __buf;
        }
    };

    /// @brief Reading data from a file (at a offset).
    /// @param __file File to read.
    /// @param __n Number of bytes (default sizeof[T])
    /// @tparam T Class to be casted to.
    /// @return T type of bytes casted.
    template<typename T>
    static const T
    freadp(const std::string& __file, const std::int64_t __o, const std::size_t __n = sizeof(T)) {
        if (std::size_t __fd = sceIoOpen(__file.c_str(), SCE_O_WRONLY|SCE_O_CREAT, 777)) {
            void* __buf;
            sceIoPread(__fd, __buf, __n, __o);
            sceIoClose(__fd);
            return (T) __buf;
        }
    };

    /// @brief Allocating to a type. (on the psvita).
    /// @tparam T Type to be casted to.
    /// @param __n Number of bytes.
    /// @return The allocated type.
    template<typename T>
    static T&
    calloc(const std::size_t __n) 
    {
        return (T&) sce_paf_bzero(sce_paf_malloc(__n));
    };

    /// @brief Free the block of memory (on the psvita).
    /// @tparam T Type class.
    /// @param __type Type class to be free'd.
    template<typename T>
    static void
    free(T& __type) 
    {
        sce_paf_free((void*)__type);
    };
};