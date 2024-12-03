// _CONSTEXPR20 vector& operator=(const vector& _Right) {
//     if (this == _STD addressof(_Right)) {
//         return *this;
//     }

//     auto& _Al       = _Getal();
//     auto& _Right_al = _Right._Getal();
//     if constexpr (_Choose_pocca_v<_Alty>) {
//         if (_Al != _Right_al) {
//             _Tidy();
//             _Mypair._Myval2._Reload_proxy(_GET_PROXY_ALLOCATOR(_Alty, _Al),
//             _GET_PROXY_ALLOCATOR(_Alty, _Right_al));
//         }
//     }

//     _Pocca(_Al, _Right_al);
//     auto& _Right_data = _Right._Mypair._Myval2;
//     _Assign_counted_range(_Right_data._Myfirst,
//     static_cast<size_type>(_Right_data._Mylast - _Right_data._Myfirst));

//     return *this;
// }