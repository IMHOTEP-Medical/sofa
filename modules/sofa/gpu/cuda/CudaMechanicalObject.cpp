/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 beta 3      *
*                (c) 2006-2008 MGH, INRIA, USTL, UJF, CNRS                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                               SOFA :: Modules                               *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include "CudaTypes.h"
#include "CudaMechanicalObject.inl"
#include <sofa/core/ObjectFactory.h>
#include <sofa/component/MappedObject.inl>

namespace sofa
{

namespace component
{

// template specialization must be in the same namespace as original namespace for GCC 4.1
// g++ 4.1 requires template instantiations to be declared on a parent namespace from the template class.
template class MechanicalObject<CudaVec3fTypes>;
template class MechanicalObject<CudaVec3f1Types>;
template class MechanicalObject<CudaRigid3fTypes>;
#ifdef SOFA_DEV
#ifdef SOFA_GPU_CUDA_DOUBLE
template class MechanicalObject<CudaVec3dTypes>;
template class MechanicalObject<CudaVec3d1Types>;
template class MechanicalObject<CudaRigid3dTypes>;
#endif // SOFA_GPU_CUDA_DOUBLE
#endif // SOFA_DEV

} // namespace component

namespace gpu
{

namespace cuda
{

SOFA_DECL_CLASS(CudaMechanicalObject)

int MechanicalObjectCudaClass = core::RegisterObject("Supports GPU-side computations using CUDA")
        .add< component::MechanicalObject<CudaVec3fTypes> >()
        .add< component::MechanicalObject<CudaVec3f1Types> >()
        .add< component::MechanicalObject<CudaRigid3fTypes> >()
#ifdef SOFA_DEV
#ifdef SOFA_GPU_CUDA_DOUBLE
        .add< component::MechanicalObject<CudaVec3dTypes> >()
        .add< component::MechanicalObject<CudaVec3d1Types> >()
        .add< component::MechanicalObject<CudaRigid3dTypes> >()
#endif // SOFA_GPU_CUDA_DOUBLE
#endif // SOFA_DEV
        ;

int MappedObjectCudaClass = core::RegisterObject("Supports GPU-side computations using CUDA")
        .add< component::MappedObject<CudaVec3fTypes> >()
        .add< component::MappedObject<CudaVec3f1Types> >()
        .add< component::MappedObject<CudaRigid3fTypes> >()
#ifdef SOFA_DEV
#ifdef SOFA_GPU_CUDA_DOUBLE
        .add< component::MappedObject<CudaVec3dTypes> >()
        .add< component::MappedObject<CudaVec3d1Types> >()
        .add< component::MappedObject<CudaRigid3dTypes> >()
#endif // SOFA_GPU_CUDA_DOUBLE
#endif // SOFA_DEV
        ;

} // namespace cuda

} // namespace gpu

} // namespace sofa
