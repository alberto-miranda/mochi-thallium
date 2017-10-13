#ifndef __THALLIUM_FUNCTION_TRAITS_HPP
#define __THALLIUM_FUNCTION_TRAITS_HPP

namespace thallium {

template<typename...>
struct types {
	using type=types;
};

template<class Sig> struct args;

template<class R, class...Args>
struct args<R(Args...)> : types<Args...> {};

template<class Sig> using args_t = typename args<Sig>::type;

/*
EXAMPLE:
template <class...Params>
void some_function(types<Params...>) {
    }

    void* fopen(const char* filename, const char* mode);

    int main(){
      some_function(args_t<decltype(fopen)>{});
    }

}
*/
#endif
