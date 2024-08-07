class Solution {
public:
    vector<string> ones = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    vector<string> tens = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    vector<string> hund = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        if (num < 10) {
            return ones[num];
        }
        if (num < 20) {
            return tens[num - 10];
        }
        if (num < 100) {
            return hund[num / 10] + (num % 10 == 0 ? "" : " " + ones[num % 10]);
        }
        if (num < 1'000) {
            return ones[num / 100] + " Hundred" + 
            (num % 100 == 0 ? "" : " " + numberToWords(num % 100));
        }
        if (num < 1'000'000) {
            return numberToWords(num / 1'000) + " Thousand" + 
            (num % 1'000 == 0 ? "" : " " + numberToWords(num % 1'000));
        }
        if (num < 1'000'000'000) {
            return numberToWords(num / 1'000'000) + " Million" + 
            (num % 1'000'000 == 0 ? "" : " " + numberToWords(num % 1'000'000));
        }
        
        return numberToWords(num / 1'000'000'000) + " Billion" + 
            (num % 1'000'000'000 == 0 ? "" : " " + numberToWords(num % 1'000'000'000));
    }
};