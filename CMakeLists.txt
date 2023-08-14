cmake_minimum_required(VERSION 3.22.1)
project(Easy2d)

set(SOURCES
    Error.cpp
    Renderer.cpp
	Sprite.cpp
	Texture.cpp 
	textureManager.cpp 
	Window.cpp 

)
add_library(Easy2d STATIC "${SOURCES}")

