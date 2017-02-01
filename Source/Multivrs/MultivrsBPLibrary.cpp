// Fill out your copyright notice in the Description page of Project Settings.

#include "Multivrs.h"
#include "MultivrsBPLibrary.h"

#include "PhysicsEngine/BodySetup.h"
#include "PhysXIncludes.h"
#include "PhysXPublic.h"

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

bool UMultivrsBPLibrary::GetStaticMeshVertex(UStaticMesh* SM, TArray<FVector>& VertexPositions, TArray<FColor>& VertexColors)
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

	//Body Setup valid?
	UBodySetup* BodySetup = SM->BodySetup;
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

		//Number of vertices
		PxU32 VertexCount = EachTriMesh->getNbVertices();

		//Vertex array
		const PxVec3* Vertices = EachTriMesh->getVertices();

		//For each vertex, transform the position to match the component Transform 
		for (PxU32 v = 0; v < VertexCount; v++)
		{
			VertexPositions.Add(P2UVector(Vertices[v]));
		}
	}

	TMap<FVector, FColor> VCMap;
	SM->GetVertexColorData(VCMap);
	
	for (int i = 0; i < VCMap.Num(); i++)
	{
		FColor c = VCMap.FindRef(VertexPositions[i]);
		VertexColors.Add(c);
	}

	return true;
}

