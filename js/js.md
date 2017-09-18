1. ```isNaN()```

    If not a number, return true.
    Code:
    ```
    if !number
      messages.push(I18n.t("invalid_form_number"))
    else
      messages.push(I18n.t("invalid_form_number_length")) if number.length < 14 || isNaN(number)
    ```
