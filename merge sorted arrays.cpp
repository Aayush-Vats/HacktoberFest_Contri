#include<bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> arr1, int n1, vector<int> arr2, int n2, vector<int> &output)
{
	int i = 0, j = 0, k = 0;

	while (i<n1 && j <n2)
	{
		if (arr1[i] < arr2[j])
			output.push_back(arr1[i++]);
		else
			output.push_back(arr2[j++]);
	}

	while (i < n1)
		output.push_back(arr1[i++]);

	while (j < n2)
		output.push_back(arr2[j++]);
}

void mergeKArrays(vector<vector<int> > v, int r, int c)
{
	vector<int> out = v[0];
	for(int i=1;i<r;i++) {
	    vector<int> output;
            mergeArrays(v[i], c, out, out.size(), output);
       	    out = output;
    }
}

int main()
{
	int r, c, temp;
    cin>>r>>c;
    vector<vector<int> > v;
    for(int i=0;i<r;i++) {
        vector<int> temp_vec;
        for(int j=0;j<c;j++) {
            cin>>temp;
            temp_vec.push_back(temp);
        }
        v.push_back(temp_vec);
    }

	mergeKArrays(v, r, c);

	for (int i=0; i < output.size(); i++)
	    cout<<output[i]<<" ";

	return 0;
}