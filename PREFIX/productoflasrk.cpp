class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            prefix.clear();
            prefix.push_back(1);
            return;
        }

        int n=prefix.size();
        prefix.push_back(prefix[n-1]*num);
    }
    
    int getProduct(int k) {
        int n=prefix.size();
        if(k>n-1) return 0;
        return prefix[n-1]/prefix[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */