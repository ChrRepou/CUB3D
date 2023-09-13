MLX42_LIBRARY=./MLX42/build/libmlx42.a
GLFW_LIBRARY=./glfw/build/src/libglfw3.a
echo "Getting submodules..."
git submodule update --init --recursive

if ([ ! -f "$GLFW_LIBRARY" ]); then
	if [ -z `which brew` ]; then
		echo "Installing Homebrew..."
		ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
		else
		echo "Homebrew found"
	fi

	echo "Updating Homebrew, please wait..."
	brew update

	if [ -z `which cmake` ]; then
		echo "Installing cmake"
			install cmake
		else
			echo "Building GLFW"
	fi

	if [ ! -f "$GLFW_LIBRARY" ]; then
			cd ./glfw && cmake -B build && cmake --build build -j4 && cd ..
		else
			echo "Building MLX42"
	fi

	if [ ! -f "$MLX42_LIBRARY" ]; then
			cd ./MLX42 && cmake -B build && cmake --build build -j4 && cd ..
		else
			echo "Building fractol"
	fi
fi