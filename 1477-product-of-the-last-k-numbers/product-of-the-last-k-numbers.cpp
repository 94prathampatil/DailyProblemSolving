class ProductOfNumbers {
public:
    vector<int> stream;
    int preMul = 1;
    ProductOfNumbers() {}
    
    void add(int num) {
        stream.insert(stream.begin(), num);
    }
    
    int getProduct(int k) {
        if(stream.empty()){
            return 0;
        }

        preMul = 1;
        for(int i = 0;i < k;i++){
            preMul *= stream[i];
        }

        return preMul;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */