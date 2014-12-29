///
/// RenderTask.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 11 Nov 2014
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// This file has the implementation of a render task for SoA
///

#pragma once

#ifndef RenderTask_h__
#define RenderTask_h__

#include <Vorb/IThreadPoolTask.h>

#include "Constants.h"
#include "VoxPool.h"

class Chunk;
class ChunkGridData;
class ChunkMeshData;
class VoxelLightEngine;

enum class RenderTaskType { DEFAULT, LIQUID };

#define RENDER_TASK_ID 0

// Represents A Mesh Creation Task
class RenderTask : public vcore::IThreadPoolTask<WorkerData> {
public:
    RenderTask() : vcore::IThreadPoolTask<WorkerData>(true, RENDER_TASK_ID) {}

    // Executes the task
    void execute(WorkerData* workerData) override;

    // Initializes the task
    void init(Chunk* ch, RenderTaskType cType);

    RenderTaskType type; 
    Chunk* chunk;
    ChunkMeshData* chunkMeshData;

private:
    void updateLight(VoxelLightEngine* voxelLightEngine);
};

#endif // RenderTask_h__