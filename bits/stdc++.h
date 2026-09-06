// Shim for clang on macOS to make <bits/stdc++.h> work with libc++
// Codeforces uses GNU G++23 (GCC 14.2) with libstdc++; macOS Apple clang uses libc++ which lacks bits/stdc++.h.
// This shim delegates to GCC's libstdc++ when compiled with g++-15, and provides a libc++-compatible
// header list when parsed by clang/clangd.
// Homebrew GCC: /opt/homebrew/bin/g++-15 -std=c++23 (CF: GNU G++23 14.2)
#pragma once

// If we're using real GCC (not clang), delegate to the actual libstdc++ header
#if defined(__GNUC__) && !defined(__clang__)
#include_next <bits/stdc++.h>
#else
// Clang + libc++ path (used by clangd / Apple clang)
// Include all standard headers that are available; use __has_include for newer C++23/26 headers.

#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

#if __has_include(<shared_mutex>)
#include <shared_mutex>
#endif
#if __has_include(<any>)
#include <any>
#endif
#if __has_include(<charconv>)
#include <charconv>
#endif
#if __has_include(<filesystem>)
#include <filesystem>
#endif
#if __has_include(<optional>)
#include <optional>
#endif
#if __has_include(<memory_resource>)
#include <memory_resource>
#endif
#if __has_include(<variant>)
#include <variant>
#endif
#if __has_include(<string_view>)
#include <string_view>
#endif

#if __has_include(<barrier>)
#include <barrier>
#endif
#if __has_include(<bit>)
#include <bit>
#endif
#if __has_include(<compare>)
#include <compare>
#endif
#if __has_include(<concepts>)
#include <concepts>
#endif
#if __has_include(<latch>)
#include <latch>
#endif
#if __has_include(<numbers>)
#include <numbers>
#endif
#if __has_include(<ranges>)
#include <ranges>
#endif
#if __has_include(<span>)
#include <span>
#endif
#if __has_include(<stop_token>)
#include <stop_token>
#endif
#if __has_include(<semaphore>)
#include <semaphore>
#endif
#if __has_include(<source_location>)
#include <source_location>
#endif
#if __has_include(<syncstream>)
#include <syncstream>
#endif
#if __has_include(<version>)
#include <version>
#endif

#if __has_include(<expected>)
#include <expected>
#endif
#if __has_include(<format>)
#include <format>
#endif
#if __has_include(<spanstream>)
#include <spanstream>
#endif
#if __has_include(<stacktrace>)
#include <stacktrace>
#endif
#if __has_include(<print>)
#include <print>
#endif
#if __has_include(<generator>)
#include <generator>
#endif
#if __has_include(<flat_map>)
#include <flat_map>
#endif
#if __has_include(<flat_set>)
#include <flat_set>
#endif
#if __has_include(<mdspan>)
#include <mdspan>
#endif

#endif
