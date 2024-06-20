
template <typename T>
class Friend {

};

template <typename T>
class Origin {

    template <typename T> friend class Friend;
    //template <typename U> friend class Friend;
};

int main() {
    Friend<int> f;
    Origin<bool> g;
}