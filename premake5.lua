workspace "OThirteen"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
 
project "OThirteen"
    location "OThirteen"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "OT_PLATFORM_WINDOWS",
            "OT_BUILD_DLL",
            "OTHIRTEEN_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "OT_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "OT_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "OT_DIST"
        symbols "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "OThirteen/vendor/spdlog/include",
        "OThirteen/src"
    }

    links
    {
        "OThirteen"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "OT_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "OT_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "OT_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "OT_DIST"
        symbols "On"

