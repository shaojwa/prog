struct dog_t
    {
      string name;
      int age;
      boost::intrusive::list_member_hook<> lru_item;
      boost::intrusive::list_member_hook<> hash_item;
      ~dog_t() {
        cout << __func__ << endl;
      }
    };

    typedef boost::intrusive::list<
      dog_t,
      boost::intrusive::member_hook<
        dog_t,
        boost::intrusive::list_member_hook<>,
        &dog_t::hash_item>> blist_hash_t;

    typedef boost::intrusive::list<
      dog_t,
      boost::intrusive::member_hook<
        dog_t,
        boost::intrusive::list_member_hook<>,
        &dog_t::lru_item> > blist_lru_t;

    class DelDog
    {
      public:
      void operator()(dog_t* delete_this)
        { delete delete_this; }
    };

    void test_blist()
    {
      dog_t *pdog = new dog_t();
      blist_hash_t hash_list;
      blist_lru_t lru_list;
      hash_list.push_back(*pdog);
      lru_list.push_back(*pdog);
      hash_list.erase_and_dispose(hash_list.iterator_to(*pdog), DelDog());
      lru_list.erase(lru_list.iterator_to(*pdog));
    }
