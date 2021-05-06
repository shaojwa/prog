```
src/common/buffer.cc: 905: FAILED assert(o+l <= p._len)
(8ca972db3d0994aadaa5f85e271c0cda4353e657) luminous (stable)
 1: (ceph::__ceph_assert_fail(char const*, char const*, int, char const*)+0x110) [0x7faeec88a530]
 2: (ceph::buffer::ptr::ptr(ceph::buffer::ptr const&, unsigned int, unsigned int)+0x4d) [0x7faeec82fefd]
```
