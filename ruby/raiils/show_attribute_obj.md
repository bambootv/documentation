`<% for attribute in current_user.attributes.keys %>
  <p><%= attribute.humanize %> <%= @user.attributes[attribute].to_s %></p>
<% end %>


<% for attribute in @user.attributes.keys %>
  <p><%= attribute.humanize %> <%= @user.attributes[attribute].to_s %></p>
<% end %>

<% if current_user == @user %>
  <h1>True</h1>
<% else %>
  <h1>Faild</h1>
<% end %>`
