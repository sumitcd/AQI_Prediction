import numpy as np
import pandas as pd
from sklearn.linear_model import Ridge

# Read the data
combined_data = pd.read_csv('city_day.csv')

# Drop rows with missing values
combined_data = combined_data.dropna()

# Define features (X) and target variable (Y)
X = combined_data[['PM2.5', 'PM10', 'NO', 'NO2','NOx','NH3','CO','SO2','O3','Benzene','Toluene','Xylene']]
Y = combined_data['AQI']

# Create a Ridge regression model
alpha = 1.0  
ridge_regr = Ridge(alpha=1)

# Fit the model to the training data
ridge_regr.fit(X, Y)


# Access the coefficients and intercept
print('Coefficients:', ridge_regr.coef_)
print('\nIntercept:', ridge_regr.intercept_)
