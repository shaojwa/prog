#### vector initilization
```
vector<string> cmd = {"show-hash-stat"};
// identical to 
vector<string> cmd({"show-hash-stat"});
```

#### map initilization
```
map<uint64, uint64> map_want = {{offset, length}};
// identical to 
map<uint64, uint64> map_want({{offset, length}});
```

#### std::mutex
