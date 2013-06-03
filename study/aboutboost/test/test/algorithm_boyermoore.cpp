#include <boost/algorithm/searching/boyer_moore.hpp>
#include <boost/algorithm/searching/boyer_moore_horspool.hpp>
#include <boost/algorithm/searching/knuth_morris_pratt.hpp>
#include <string>
using namespace std;
int main()
{
    string strPatt = "abcdcba";
    string strBuff = "ajdabcdcbancaidabcdceqonfkabcasnafuababgjsabcdcbakhf";
    string strBuff2 = "ajdabcdcbncaidabcdceqonfkabcasnafuababgjsabcdcbakhf";
    // 1 boyer_moore
    boost::algorithm::boyer_moore<string::iterator> searchObj(strPatt.begin(), strPatt.end());
    string::iterator it = searchObj(strBuff.begin(), strBuff.end());

    it = boost::algorithm::boyer_moore_search(strBuff2.begin(), strBuff2.end(), strPatt.begin(), strPatt.end());
    
    






    return 0;
}