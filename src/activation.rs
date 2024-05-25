pub struct Activation {}

impl Activation {
    pub fn sigmoid(x: f64) -> f64 {
        1.0 / (1.0 + (-x).exp())
    }

    pub fn sigmoid_derivative(x: f64) -> f64 {
        x * (1.0 - x)
    }

    pub fn relu(x: f64) -> f64 {
        if x > 0.0 {
            return x;
        } else {
            return 0.0;
        }
    }

    pub fn relu_derivative(x: f64) -> f64 {
        if x > 0.0 {
            return 1.0;
        } else {
            return 0.0;
        }
    }

    pub fn tanh_derivative(x: f64) -> f64 {
        1.0 - (x * x)
    }
}