// Fill out your copyright notice in the Description page of Project Settings.

#include "Multivrs.h"
#include "MultivrsBPLibrary.h"

#include "PhysicsEngine/BodySetup.h"
#include "PhysXIncludes.h"
#include "PhysXPublic.h"

#include "StaticMeshResources.h"

bool UMultivrsBPLibrary::GetStaticMeshVertexLocations(UStaticMeshComponent* Comp, TArray<FVector>& VertexPositions)
{
	VertexPositions.Empty();

	if (!Comp)
	{
		return false;
	}
	if (!Comp->IsValidLowLevel())
	{
		return false;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~

	//Component Transform
	FTransform RV_Transform = Comp->GetComponentTransform();

	//Body Setup valid?
	UBodySetup* BodySetup = Comp->GetBodySetup();
	if (!BodySetup || !BodySetup->IsValidLowLevel())
	{
		return false;
	}

	for (PxTriangleMesh* EachTriMesh : BodySetup->TriMeshes)
	{
		if (!EachTriMesh)
		{
			return false;
		}
		//~~~~~~~~~~~~~~~~

		//Number of vertices
		PxU32 VertexCount = EachTriMesh->getNbVertices();

		//Vertex array
		const PxVec3* Vertices = EachTriMesh->getVertices();

		//For each vertex, transform the position to match the component Transform 
		for (PxU32 v = 0; v < VertexCount; v++)
		{
			VertexPositions.Add(RV_Transform.TransformPosition(P2UVector(Vertices[v])));
		}
	}

	return true;

	/*
	//See this wiki for more info on getting triangles
	//		https://wiki.unrealengine.com/Accessing_mesh_triangles_and_vertex_positions_in_build
	*/
}

bool UMultivrsBPLibrary::GetStaticMeshVertexInfo(UStaticMeshComponent* SM, TArray<FVector>& VertexPositions, TArray<FColor>& VertexColors)
{
	VertexPositions.Empty();
	VertexColors.Empty();

	if (!SM)
	{
		return false;
	}
	if (!SM->IsValidLowLevel())
	{
		return false;
	}

	FPositionVertexBuffer* VertexBuffer = &SM->GetStaticMesh()->RenderData->LODResources[0].PositionVertexBuffer;
	FColorVertexBuffer* ColorBuffer = &SM->GetStaticMesh()->RenderData->LODResources[0].ColorVertexBuffer;

	if (VertexBuffer)
	{
		const int32 VertexCount = VertexBuffer->GetNumVertices();
		for (int32 Index = 0; Index < VertexCount; Index++)
		{
			// Converts the UStaticMesh vertex into world actor space including Translation, Rotation, and Scaling
			const FVector WSLocation = SM->GetOwner()->GetTransform().TransformVector(VertexBuffer->VertexPosition(Index));
			VertexPositions.Add(WSLocation);

			const FColor Color = ColorBuffer->VertexColor(Index);
			VertexColors.Add(Color);
		}
	}
	else
		return false;

	return true;
}
