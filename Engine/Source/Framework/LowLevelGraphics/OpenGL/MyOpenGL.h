#pragma once
#include "Universal/Macro.h"
#include "Universal/UniversalTypeDefs.h"
#include "GL/glew.h"
#include "Math/Vector3D.h"
#include "Universal/UniversalTypeDefs.h"
#include "DataStructures/Vector.h"
#include <iostream>
#include <fstream>

namespace MyOpenGL
{
	void InitializeBuffers(int64 sizeOfGeometry, const void* GeometryDataFirstElement, int64 sizeOfIndicies, const void* indicieDataFirstElement, uint32* vertexBufferID, uint32* indexBufferID);
	std::string ReadShaderCode(const char8* cFileName, const char8* cTypeOfShader);
	void InstallShaders();
	void sendUniformMat4Data(const char8* whatShaderVariableToSendTo, GLfloat* matrixData);//TODO: Rename to SendUniformDataMat4
	void sendUniformVec2Data(const char8* whatShaderVariableToSendTo, GLfloat* matrixData);
	void Draw(uint32 vertexBufferID, uint32 indexBufferID, uint16 numOfIndicies);
}
