# Load dữ liệu từ file CSV
import pandas as pd
data = pd.read_csv('ten_file.csv')

# Tiền xử lý dữ liệu
from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
X = data.drop('target_variable', axis=1)  # Bỏ cột biến đầu ra
X = scaler.fit_transform(X)  # Tiêu chuẩn hóa dữ liệu
y = data['target_variable']  # Biến đầu ra

# Tạo tập train và tập test
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Xây dựng model và train model
from sklearn.linear_model import LogisticRegression
model = LogisticRegression()
model.fit(X_train, y_train)

# Dự đoán kết quả trên tập test
y_pred = model.predict(X_test)

# Vẽ đồ thị
import matplotlib.pyplot as plt
from sklearn.metrics import plot_confusion_matrix
plot_confusion_matrix(model, X_test, y_test)
plt.show()
