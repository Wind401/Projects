ActiveAdmin.register User do

# See permitted parameters documentation:
# https://github.com/activeadmin/activeadmin/blob/master/docs/2-resource-customization.md#setting-up-strong-parameters

    index do
      selectable_column
      column :first_name
      column :last_name
      column :email
      column :birthday
      column :address
      column :dog_breed
      column :dog_height
      column :dog_weight
      column :dog_age
      column :about
      column :created_at
      column :updated_at
      actions
    end

permit_params :list, :of, :attributes, :on, :model
#
# or
#
# permit_params do
#   permitted = [:permitted, :attributes]
#   permitted << :other if params[:action] == 'create' && current_user.admin?
#   permitted
# end


end
