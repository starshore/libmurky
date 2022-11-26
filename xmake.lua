-- libmurky

set_defaultarchs("windows|x64", "windows|x86")

add_rules("mode.releasedbg")
add_rules("plugin.vsxmake.autoupdate")

-- libmurky.dll
target("libmurky", function()
    -- for dll
    set_kind("shared")
    -- include
    add_includedirs("include")
    -- public header
    add_headerfiles("include/**.h")
    -- private header
    add_headerfiles("src/**.h", { install = false })
    -- source
    add_files("src/**.c")
    -- exports
    add_files("src/**.def")
    -- compiler flags
    add_cflags("/Gz", "/GS-")
    -- linker flags
    add_shflags("/NODEFAULTLIB", "/ENTRY:DllMain", { force = true })
    -- remove pdb abs path
    add_shflags("/PDBALTPATH:%_PDB%", { force = true })
end)

-- libmurky_test.exe
add_requires("spdlog", "doctest")
target("libmurky_test", function()
    -- for exe
    set_kind("binary")
    -- include
    add_includedirs("include")
    -- private header
    add_headerfiles("test/**.h", { install = false })
    -- source
    add_files("test/**.cpp")
    -- for doctest entry
    add_defines("DOCTEST_CONFIG_IMPLEMENT")
    -- deps
    add_deps("libmurky")
    add_packages("spdlog", "doctest")
end)
