workspace "GreenSky"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GreenSky"
	location "GreenSky"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")


	pchheader "gspch.h"
	pchsource "GreenSky/src/gspch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/assimp/include",
		"%{prj.name}/vendor/freetype",
		"%{prj.name}/vendor/GLEW/include",
		"%{prj.name}/vendor/GLFW/include",
		"%{prj.name}/vendor/glm",
		"%{prj.name}/vendor/irrklang/include",
		"%{prj.name}/vendor/nlohmann"
	}

	libdirs {
		"%{prj.name}/vendor/assimp/lib",
		"%{prj.name}/vendor/GLEW/lib",
		"%{prj.name}/vendor/GLFW/lib-vc2019",
		"%{prj.name}/vendor/irrklang/lib",
	}

	links {
		""
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"GS_PLATFORM_WINDOWS",
			"GS_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GS_DIST"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"GreenSky/vendor/spdlog/include",
		"GreenSky/src"
	}

	links {
		"GreenSky"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"GS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GS_DIST"
		optimize "On"
