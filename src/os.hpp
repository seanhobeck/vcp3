/**
 * 
 * 
 *   @author Sean Hobeck
 * 
 *    @date 02/10/2023
 * 
 * 
 **/
#pragma once

/// @uses: scekernel functions
#include "bits.hpp"

#include <memory>

#include <string>

/// @brief vita cplusplus port namespace
namespace vstd
{
    /// @brief Exit the current process.
    /// @param e Error number.
    static void exit(std::int32_t e = 0) noexcept { sceKernelExitProcess(e); };

    /// @brief Formatting a string to a output buffer with {__n}, number of characters.
    /// @tparam pargs_t Packed arguments.
    /// @param __buf Output std::string buffer.
    /// @param __n Number of bytes to copy.
    /// @param __format String to be formatted.
    /// @param args Format arguments.
    template <typename ... pargs_t>
    static void
    printf(const std::string& __format, pargs_t... args)
    {
        fprintf(stdout, __format.c_str(), args...);
    };
    
    /// @brief Formatting a wide string to a output buffer with {__n}, number of characters.
    /// @tparam pargs_t Packed arguments.
    /// @param __buf Output std::wstring buffer.
    /// @param __n Number of bytes to copy.
    /// @param __format String to be formatted.
    /// @param args Format arguments.
    template <typename ... pargs_t>
    static void
    wprintf(const std::wstring& __format, pargs_t... args)
    {
        fwprintf(stdout, __format.c_str(), args...);
    };
};