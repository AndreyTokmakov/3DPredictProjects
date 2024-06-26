//============================================================================
// Name        : Jaw.cpp
// Created on  : 10.12.2021.
// Author      : Tokmakov Andrey
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Jaw
//============================================================================

#include "Jaw.h"


namespace Model {

    Jaw::Jaw(const std::unordered_map<unsigned short, vtkSmartPointer<vtkPolyData>>& toothMap,
             TeethType jawSide): side {jawSide}
    {
        teeth.reserve(FDI::MAX_TEETH_NUM_PER_JAW_SIDE);
        for (const auto& [id, ptrData]: toothMap) {
            if (TeethType::Lower == side && FDI::isLowerTooth(id))
                teeth.emplace_back(ptrData, id);
            else if (TeethType::Upper == side && FDI::isUpperTooth(id))
                teeth.emplace_back(ptrData, id);
        }
        teeth.shrink_to_fit();
    }
}