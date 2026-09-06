/*
** EPITECH PROJECT, 2020
** ex05
** File description:
** ex05
*/

#ifndef ex05_hpp
#define ex05_hpp

template<typename T> class array {
    public:
        array() {
            _stockage = nullptr;
            _size = 0;
        };
        array(unsigned int n) {
            _size = n;
            _stockage = new T[n]();
        };
        array(const array &a) {
            _size = a._size;
            _stockage = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _stockage[i] = a._stockage[i];
        };
        virtual ~array() {
            if (_stockage)
                delete[] _stockage;
        };
        unsigned int size() const {
            return (_size);
        };
        T &operator[](unsigned int index) {
            if (index > _size) {
                T *aaaaaa = new T[index + 1]();
                for (unsigned int i = 0; i < _size; i++)
                    aaaaaa[i] = _stockage[i];
                delete[] _stockage;
                _stockage = aaaaaa;
                _size = index + 1;
            }
            return (_stockage[index]);
        };
        T &operator[](unsigned int index) const {
            if (index > _size)
                throw (std::exception());
            return (_stockage[index]);
        };
        array &operator=(const array &a) {
            _size = a._size;
            if (_stockage) {
                delete[] _stockage;
                _stockage = nullptr;
            }
            _stockage = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _stockage[i] = a._stockage[i];
            return (*this);
        };
        void dump() const {
        	std::cout << "[";
            for (unsigned int i = 0; i < _size; i++) {
                std::cout << _stockage[i];
                if (i + 1 < _size)
                std::cout << ", ";
            }
        	std::cout << "]" << std::endl;
        };
        template<typename U>
        array<U> convertTo(U(*convert)(const T &)) const {
            array<U> element(_size);
            for (unsigned int i = 0; i < _size; i++)
                element[i] = (*convert)(_stockage[i]);
            return (element);
        }

    private:
        unsigned int _size = 0;
        T *_stockage = nullptr;
};


template<>
void array<bool>::dump() const {
	std::cout << "[";
    for (unsigned int i = 0; i < _size; i++) {
		std::cout << (_stockage[i] ? "true" : "false");
		if (i + 1 < _size) {
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
}

#endif /* !ex05_hpp */
