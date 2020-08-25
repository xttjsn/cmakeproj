include(GoogleTest)
include(ExternalProject)

ExternalProject_Add(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.8.0
  PREFIX googletest
  # Disable install step
  INSTALL_COMMAND ""
  CMAKE_CACHE_ARGS
    -DCMAKE_BUILD_TYPE:STRING=Release
    -DBUILD_GMOCK:BOOL=ON
    -DBUILD_GTEST:BOOL=ON
    -Dgtest_force_shared_crt:BOOL=OFF
)

ExternalProject_Get_Property(googletest source_dir)
set(GTEST_SOURCE_DIR ${source_dir})
ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_BINARY_DIR ${binary_dir})

# Setup gtest / gmock libraries and include dirs
set(LIBGTEST_LIBRARIES
  "${GTEST_BINARY_DIR}/${CMAKE_CFG_INTDIR}/googlemock/gtest/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}"
  "${GTEST_BINARY_DIR}/${CMAKE_CFG_INTDIR}/googlemock/gtest/${CMAKE_STATIC_LIBRARY_PREFIX}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}"
)
set(LIBGMOCK_LIBRARIES
  "${GTEST_BINARY_DIR}/${CMAKE_CFG_INTDIR}/googlemock/${CMAKE_STATIC_LIBRARY_PREFIX}gmock${CMAKE_STATIC_LIBRARY_SUFFIX}"
  "${GTEST_BINARY_DIR}/${CMAKE_CFG_INTDIR}/googlemock/${CMAKE_STATIC_LIBRARY_PREFIX}gmock_main${CMAKE_STATIC_LIBRARY_SUFFIX}"
)
set(LIBGMOCK_INCLUDE_DIR "${source_dir}/googlemock/include")
set(LIBGTEST_INCLUDE_DIR "${source_dir}/googletest/include")
