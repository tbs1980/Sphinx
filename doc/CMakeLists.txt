cmake_minimum_required(VERSION 2.8)

find_package(Doxygen)

if(DOXYGEN_FOUND)
    set (doxygenConfigFileIn "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
    set (doxygenConfigFile "${CMAKE_CURRENT_BINARY_DIR}/sphnixCpp.dox")
    configure_file(${doxygenConfigFileIn} ${doxygenConfigFile} @ONLY)
    add_custom_target (Docs
        ${DOXYGEN_EXECUTABLE} ${doxygenConfigFile}
        DEPENDS ${doxygenConfigFile}
    VERBATIM)
endif(DOXYGEN_FOUND)

find_package(Sphinx REQUIRED)

# configured documentation tools and intermediate build results
set(BINARY_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/_build")

# Sphinx cache with pickled ReST documents
set(SPHINX_CACHE_DIR "${CMAKE_CURRENT_BINARY_DIR}/_doctrees")

# HTML output directory
set(SPHINX_HTML_DIR "${CMAKE_CURRENT_BINARY_DIR}/html")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/conf.py.in"
    "${BINARY_BUILD_DIR}/conf.py"
@ONLY)

add_custom_target(sphnixC++Docs ALL
    ${SPHINX_EXECUTABLE}
    -q -b html
    -c "${BINARY_BUILD_DIR}"
    -d "${SPHINX_CACHE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${SPHINX_HTML_DIR}"
COMMENT "Building HTML documentation with Sphinx")
