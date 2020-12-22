```
if (WITH_DM)
  add_definitions(-DDCACHE_GTEST_DM)
  set(dcache_dm_test_srcs
  ${PROJECT_SOURCE_DIR}/src/googletest/googletest/src/gtest_main.cc
  dm/dcache_dm_test.cc)
  add_executable(dcache-dm-test ${dcache_dm_test_srcs})
  target_link_libraries(dcache-dm-test
      dcache
      global-static
      ceph-common
      libgo
      gcov
      ${UNITTEST_LIBS}
      )
endif(WITH_DM)
```
