# XGBoost regression salary model
> 23-04-2020

This simple xgboost model aims to predict the salary of developers based on their background characteristics. Please see [the sclbl 101 notebook](https://github.com/scailable/sclbl-demos/blob/master/sclbl-101-getting-started/sclbl-demo.ipynb) for more information.

The input feature_vector consists of the following fields:

1. `f_open`: Dummy indicating frequent contributions to open-source projects.
2. `f_employed`: Indicator whether the respondent is employed.
3. `f_selfemployed`: Indicator whether the respondent is self-employed.
4. `f_unemployed`: Indicator whether the respondent is unemployed.
5. `f_education`: Education level, `0=low`, `2=high`.
6. `f_organization`: Indicator whether the respondent works in a large `>500` organization.
7. `f_datascientist`: Indicator whether the respondent identifies as Data Scientists. 
8. `f_designer`: Indicator whether the respondent identifies as Designer.
9. `f_developer`: Indicator whether the respondent identifies as Developer. 
10. `f_devops`: Indicator whether the respondent identifies as DevOps Engineer. 
11. `f_engineer`: Indicator whether the respondent identifies as Engineer. 
12. `f_scientist`: Indicator whether the respondent identifies as Scientists. 
13. `f_years`: Number of years coding experience.
14. `f_yearspro`: Number of years professional coding experience. 
15. `f_ambition`: Indicator signaling ambition to become a manager. 
16. `f_python`: Indicator uses `python`.
17. `f_r`: Indicator uses `[R]`.
18. `f_age`: Age of the respondent.
19. `f_female`: Indicator `female`. 
20. `f_male`: Indicator `male`.
21. `f_other`: Indicator `other`.

Thus, the following feature vector 

```
[ 0,  1,  0,  0,  1,  0,  0,  1,  1,  0,  0,  0,  3,  1,  0,  0,  0, 28,
  0,  1,  0,]

```
describes a 28 old male who is currently employed and has 3 years of coding experience.  