class UndergroundSystem {
public:
unordered_map<int,pair<string,int>>checkin;
unordered_map<string,pair<int,int>>checkout;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto coutt=checkin[id];
        checkin.erase(id);
        // int checko=t-coutt.second;
        
         string route = coutt.first + "_" + stationName;
        checkout[route].first+=t-coutt.second;
        checkout[route].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        auto time=checkout[route];
        return (double)time.first/time.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */