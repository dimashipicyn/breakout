
add_subdirectory(gui)

target_sources(${PROJECT_NAME} PUBLIC
    main.cpp
	ball.cpp
	Rocket.cpp
	Block.cpp
	Level.cpp
    GameLogic.h
	GameLogic.cpp
	ball.hpp
	Rocket.hpp
	Block.hpp
	Level.hpp
)
