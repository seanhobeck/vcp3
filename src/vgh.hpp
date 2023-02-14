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


/// @brief A class for a vector3.
class vecf
{
private:

    /// x, y, z coordinates
    float x, y, z;

public:

    ///---------- Constructors -----------///

    vecf() : x(0.f), y(0.f), z(0.f) {};
};