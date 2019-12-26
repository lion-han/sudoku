# sudoku-
 A software engineering personal project
# 软件工程个人项目— 数独 

 1120173032   王晗 

## PSP2.1 表格

| PSP2.1                                | Personal Software ProcessStages      | 预估耗时（分钟） | 实际耗时（分钟） |
| ------------------------------------- | ------------------------------------ | ---------------- | ---------------- |
| Planning                              | 计划                                 | 60               |                  |
| Estimate                              | 估计这个任务需要多少时间             | 1500             |                  |
| Development                           | 开发                                 | 700              |                  |
| Analysis                              | 需求分析 (包括学习新技术)            | 180              |                  |
| Design Spec                           | ·生成设计文档                        | 100              |                  |
| Design Review                         | 设计复审 (和同事审核设计文档)        | 50               |                  |
| Coding Standard                       | 代码规范 (为目前的开发制定合适的规范 | 30               |                  |
| Design                                | · 具体设计                           | 80               |                  |
| Coding                                | 具体编码                             | 650              |                  |
| Code Review                           | 代码复审                             | 60               |                  |
| Test                                  | 测试（自我测试，修改代码，提交修改） | 80               |                  |
| Reporting                             | 报告                                 | 120              |                  |
| Test Report                           | 测试报告                             | 60               |                  |
| Size Measurement                      | 计算工作量                           | 30               |                  |
| Postmortem & Process Improvement Plan | 事后总结, 并提出过程改进计划         | 40               |                  |
|                                       | 合计                                 |                  |                  |



## 个人日报：

| 日期  | 工作情况                                 | 耗时  |
| ----- | ---------------------------------------- | ----- |
| 12.23 | 分析并选题                               | 60min |
| 12.24 | 创建博客、github仓库、需求分析、解题思路 | 60min |
| 12.25 | 解题思路                                 | 30min |
| 12.26 | 学习DLX算法、实现生产数独终局模块        |       |
|       |                                          |       |
|       |                                          |       |
|       |                                          |       |
|       |                                          |       |
|       |                                          |       |

## 结题思路：

### 生成终局

在研究数独时发现，想要生成数目庞大的数独终局，不能通过随机的分配或者一位一位产生，必须通过一定规律的变化得到。

我发现通过确定第一行的数，后面7行通过对第一行不同的移位可产生一个数独终局。由于每个3*3的方块内不能有重复的数，所以1、2、3行，4、5、6行，7、8、9行内位移必须大于等于3，不然会出现重复。

通过变化第一行的数顺序，其余7行移位规律不变（），可产生8！=40320个终局（第一位固定，后面7行移位规律相同）

之后可以通过2、3行，4、5、6行，7、8、9行内交换任意两行可得到不同的矩阵，共2*6\*6=72种变化

通过上述变化可产生 8! \*（2*6\*6)=2903040>1e6 可满足条件

## 
