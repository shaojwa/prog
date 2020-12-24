```
void dm_objsnap_t::snap_write_fragment(
    const hobject_t &hobj, uint16 bucket_id,
    uint64 offset, uint64 length, const bufferlist &data)
{
  dm->get_co_sched()->CreateTask([this, hobj, bucket_id, off, len] {
    this->dm->do_filling_read(hobj, this->snap_seq, bucket_id, off, len);},
    ::co::TaskOpt(UINT16_MAX, UINT16_MAX, dm->get_thread_id(),
    true, 0, 0, __func__, __FILE__, __LINE__));
 }
 ```
