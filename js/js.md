1. ```isNaN()```

    If not a number, return true.
    Code:
    ```
    if !number || isNaN(number)
      messages.push(I18n.t("invalid_form_cc_number"))
    else
      messages.push(I18n.t("invalid_form_cc_number_length")) if cc_number.length < 14
    ```
