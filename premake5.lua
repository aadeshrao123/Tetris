workspace "Tetris"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

	startproject "Tetris"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Tetris"
	location "Tetris"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediate/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Vendor/raylib/include"
	}

	links 
	{ 
		"raylib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		buildoptions "/MDd"
		symbols "On"

		libdirs
		{
			"%{prj.name}/Vendor/raylib/Debug"
		}
		links
		{
			"raylib",
			"winmm.lib"
		}

	filter "configurations:Release"
		buildoptions "/MD"
		optimize "On"

		libdirs
		{
			"%{prj.name}/Vendor/raylib/Release"
		}
		links
		{
			"raylib",
			"winmm.lib"
		}
