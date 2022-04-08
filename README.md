# LeetCode_ED
记录一下自己的刷题记录.
- 好久没有用到的`getline`
  用来对字符串进行分隔
  一般来说常常先将待处理字符串输入一个字符串流
  然后使用`while`循环不断分隔处理
  ```c++
  string target;
  stringstream ss;
  ss<<target;
  while(getline(ss,target,char))
  {
    ...
  }
  ```

- 判断数组元素是否为0时,使用显示判断`t==0`的速度要快于隐式判断`!t`

- 最简单的二分模板
  ```c++
  int left=1,right=n;
  int mid=0;
  while(left<=right)
  {
      mid=(left+right)/2;
      if(isBadVersion(mid))
          right=mid-1;
      else
          left=mid+1;
  }
  return left;
  ```


- 库函数
  - C++库函数`next_permutation(it.begin(),it.end())`,将所有元素按照字典序排列组合后,返回当前排序的下一个
    实际上函数内部应该不是这样做的.
  - 现成的库函数`reverse(it.begin(),it.end())`,可以直接将传入的元素反序排列



- 回忆一下如何使用优先队列
  ```c++
  priority_queue<type,container_type<type>,less/geater<type>>;
  ```
  优先队列中默认使用的是大根堆.也就是说,如果在第三个参数处没有明确指明`less`/`greater`,则默认使用`less`,数值较大者优先.
  当使用`greater`时,变成小根堆,此时数值较小者优先.

  如果想要使用自定义结构体的优先级队列, 那么需要在结构体内对比较运算符进行重载:
  - 如果使用的是默认的`less`,需要对小于号`<`进行内容重载.形式如下:
    ```c++
    struct Type
    {
      int a;
      bool operator<(const Type& b) const
      {
        if...
      }
    };
    ```
  - 同样的道理,如果想要使用`greater`,需要对大于号`>`进行重载.

- 如何获得某种类型的迭代器?
  以`vector`为例
  ```c++
  bool Compare(vector<int>::iterator a,vector<int>::iterator b);
  ```

- 今天的每日一题:
  如果一个vector中的每个元素都有相同的值,那么比较好的方法应该是通过在初始赋值时,通过设定初始值完成全部元素的赋值,形如
  ```c++
  vector<vector<int>> nums(initSize,initVal);
  ```
  如果不确定的话,可以在数量确定之后,使用resize函数进行重新赋值:
  ```c++
  nums.resize(newSize,newVal);
  ```
  需要注意的是,如果初始数组已经初始化了,也就是已经有值了,那么通过resize方法,只会对后面新增的数组内容赋值newVal,原val值不变.
  如果初始数组没有初始化过,那么使用该方法比较快捷.
  给出例子:
  ```c++
  vector<int> nums(10,5);
  for(auto &it:nums) cout<<it<<" ";
  cout<<endl;
  
  nums.resize(15,2);
  for(auto &it:nums) cout<<it<<" ";
  cout<<endl;
  ```
  输出值:
  > 5 5 5 5 5 5 5 5 5 5
  > 5 5 5 5 5 5 5 5 5 5 2 2 2 2 2

- TNND!为什么每次自己考虑的都不够全面!!
  想办法把所有可能的情况都考虑到真是个大难事啊

- 感觉很久不刷题手太生疏了!!!(2022/03/24)
  首先记录一下vector构建矩阵的方式:
  ```c++
  vector<vector<int>> nums(nRows,vector<int>(nCols));
  ```
  这实际上是通过构建每个单元为vector的vector来完成.
- 前缀和
  对于矩阵的前缀和求解,脑海中最好要有矩阵的图!另外,求某一块区域的时候记得要将待求解的上界和左界-1.确保求取区域准确!

- 字典序排序(2022/03/23)
  今天的每日一题是关于字典序得问题,并且难度为hard.
  首先记录一下自己提交时出错的点:
  - 首先是对于map得错误认知,以为通过将分割点,例如`1`,`10`,`100`,`2`,等等直接入map后的排序就是想要得到的字典序,但是发现这样的想法肯定是错误地!
  
  - 后来想到能否将分割点得数字转换为string类型,然后存入map中,然后再从map中一次取,这样取到的应该就是字典序了.结果只过了前25个点.然后发现对于测试点:
    ```c++
    100
    10
    ans:
    17
    ```
    
    怎么都过不去,想了想原来是自己理解的问题.即对于`1 10 11 100 109 110 2`
    
    其字典序排序应当是:
    
    `1 10 100 109 11 110 2`
    
    而自己一开始的理解是通过`1 10 100 `将所有数字进行分隔,然后记录每个分隔后到下一个分隔之间的数字个数,根据前缀和求解.后来发现自己的理解大错特错!
  
  - [ ] :face_with_head_bandage:先在这里留个坑,记录一下官方题解的入口,等有时间再来看一看.
  
    [字典序的第K小数字 - 字典序的第K小数字 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/zi-dian-xu-de-di-kxiao-shu-zi-by-leetcod-bfy0/)


- 对于字符串的删除操作(2022/03/22)
  今天的每日一题中出现了对于字符串的处理,自己开始想着通过删除进行暴力更新,但是删除过程中存在问题,即自己料想的删除后的字符串与实际删除后的字符串相差较大.
  后来发现问题出在对于`erase`参数的认识不清:
  `erase`函数包括四个重载:
  - 给定一个迭代器:删除此迭代器指向的字符.
  - 给定两个迭代器:删除两个迭代器之间的字符,注意两个迭代器的关系为[)
  - 给定一个数字:数字代表字符串中字符的下标,删除字符下标及其之后的所有字符
  - 给定两个数字:前者代表字符串中字符的下标,后者代表要删除的字符的长度.


- 针对LeetCode的测试方式的猜想

  由于题解是以类的形式给出的,因此我们可以猜测是否是对每一个测试点都作为一个类对象,调用其中的对应函数进行求解.

  产生这样的猜想是根据T653,求解中将变量设置外**类外**的全局变量,结果发现每次都会卡在一个测试点,调试发现这个全局变量中的内容远大于测试点给定的内容,而当讲该全局变量更改为类内变量后,就没有出现这样的情况了.

- 关于`unordered_map`

  无序容器,和map容器一样的是通过键值对方式存储数据,存储的各个键值对的键互不相同且**不允许被修改**.不同的是`unorder_map`不会对数据进行排序:容器底层采用的是**哈希表存储结构**，该结构本身不具有对数据的排序功能，所以此容器内部不会自行对存储的键值对进行排序.

  因为两者的底层实现的结构不同的原因,`map`以**红黑树**结构实现,每次操作的时间复杂度接近于$O(logn)$,而后者以**哈希表**实现,每次操作虽然存在冲突,但是大多数情况下其时间复杂度接近于$O(1)$.

  由此可以推断两者不同的适用场景:

  - `unorde_map`适用于要求查找速率快,且对单次查询性能要求不敏感的情况.
  - `map`适用于:
    - 元素需要有序
    - 对于单次查询时间较为敏感,必须保持查询性能的稳定性,比如实时应用等等.

  
