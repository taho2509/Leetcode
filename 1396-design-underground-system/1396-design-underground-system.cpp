class UndergroundSystem {
    unordered_map<int,pair<string, int>> traveling;
    unordered_map<string,pair<int,int>> times;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        traveling[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = traveling[id];
        string key = startStation + "-" + stationName;
        if(times.count(key) == 0) {
            times[key] = {t - startTime, 1};
        } else {
            times[key] = {times[key].first + (t - startTime), times[key].second + 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "-" + endStation;
        if(times.count(key) == 0) return 0;
        
        return (double) times[key].first/(double)times[key].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */