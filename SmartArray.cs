using System;

namespace Task1
{
    class SmartArray
    {
        private int[] array;
        private int minIndex;
        public int MinIndex
        {
            get { return minIndex; }
        }

        private int maxIndex;
        public int MaxIndex
        {
            get { return maxIndex; }
        }

        private int sizeArr;
        public int SizeArr
        {
            get { return sizeArr; }
        }
        private void InitializeArray()
        {
            if (minIndex < 0 && maxIndex > 0)
            {
                sizeArr = ((minIndex * -1) + maxIndex) + 1;
            }
            else if(minIndex == 0)
            {
                sizeArr = minIndex + maxIndex + 1;
            }
            else if(minIndex < 0 && maxIndex < 0)
            {
                sizeArr = (minIndex + maxIndex) * -1;
            }
            else if (maxIndex == 0)
            {
                sizeArr = (minIndex * -1) + 1;
            }
            else
            {
                sizeArr = minIndex + maxIndex;
            }

            array = new int[sizeArr];
        }
        public SmartArray()
        {
            maxIndex = 10;
            minIndex = 0;
            InitializeArray();
        }

        public SmartArray(int _minIndex, int _maxIndex)
        {
            minIndex = _minIndex;
            maxIndex = _maxIndex;
            InitializeArray();
        }

        public int this[int index]
        {
            get
            {
                return array[sizeArr - ((maxIndex - index) + 1)];
            }
            set
            {
                array[sizeArr - ((maxIndex - index) + 1)] = value;
            }
        }
    }
}
