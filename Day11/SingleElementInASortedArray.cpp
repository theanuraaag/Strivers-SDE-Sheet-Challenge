int singleNonDuplicate(vector<int> &arr)

{

  int start = 0;

  int end = arr.size() - 1;

  if (arr[0] != arr[1])

    return arr[0];

  else if (arr[end] != arr[end - 1])

    return arr[end];

  else if (end == 0)

    return arr[0];

  while (start < end) {

    int mid = start + (end - start) / 2;

    if (mid % 2 == 0) {

      if (arr[mid] == arr[mid + 1]) {

        start = mid + 2;

      }

      else

        end = mid;

    }

    else {

      if (arr[mid] == arr[mid - 1]) {

        start = mid + 1;

      }

      else

        end = mid - 1;
    }
  }

  return arr[start];
}
