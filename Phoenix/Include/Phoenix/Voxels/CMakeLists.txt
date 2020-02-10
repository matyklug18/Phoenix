set(currentDir ${CMAKE_CURRENT_LIST_DIR})
set(voxelHeaders
	${currentDir}/Block.hpp
	${currentDir}/BlockRegistry.hpp
	${currentDir}/TextureRegistry.hpp
	${currentDir}/Chunk.hpp
	${currentDir}/ChunkManager.hpp
	${currentDir}/Item.hpp
	${currentDir}/Inventory.hpp

	PARENT_SCOPE
)
