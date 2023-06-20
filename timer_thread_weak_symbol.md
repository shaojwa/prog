```
[SDS_Admin@fpnode191 dcache]$ nm /opt/h3c/bin/dse | grep timer_thread | c++filt
000000000042cfc0 W ceph::timer_detail::timer<ceph::time_detail::mono_clock>::timer_thread()
```
