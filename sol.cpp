#include <iostream>
#include <vector>
#include <numeric>

// Sử dụng long long để tránh tràn số khi tính toán
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX_VALUE = 20;

int main() {
    // Tăng tốc độ nhập xuất
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int q;
    std::cin >> q;

    // Xử lý từng truy vấn
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        // Chuyển về chỉ số 0-based cho dễ xử lý trong C++
        l--; 
        r--;

        // dp[v]: số dãy con không giảm kết thúc bằng giá trị v
        std::vector<ll> dp(MAX_VALUE + 1, 0);

        // Duyệt qua các phần tử trong đoạn [l, r] của truy vấn
        for (int i = l; i <= r; ++i) {
            int current_value = a[i];

            // Tính số dãy con mới được tạo ra và kết thúc bằng current_value
            // Bắt đầu bằng 1 (cho dãy chỉ chứa chính nó)
            ll new_subsequences = 1;

            // Cộng thêm tất cả các dãy con đã có kết thúc bằng giá trị <= current_value
            for (int v = 1; v <= current_value; ++v) {
                new_subsequences = (new_subsequences + dp[v]) % MOD;
            }

            // Cập nhật tổng số dãy con kết thúc bằng current_value
            dp[current_value] = (dp[current_value] + new_subsequences) % MOD;
        }

        // Tính tổng số dãy con không rỗng
        ll total_non_empty = 0;
        for (int v = 1; v <= MAX_VALUE; ++v) {
            total_non_empty = (total_non_empty + dp[v]) % MOD;
        }

        // Cộng 1 cho dãy rỗng theo yêu cầu đề bài
        ll final_answer = (total_non_empty + 1) % MOD;
        std::cout << final_answer << "\n";
    }

    return 0;
}