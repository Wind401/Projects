class AddDetailsToUser < ActiveRecord::Migration
  def change
    add_column :users, :first_name, :string
    add_column :users, :last_name, :string
    add_column :users, :birthday, :date
    add_column :users, :dog_breed, :string
    add_column :users, :dog_height, :integer
    add_column :users, :dog_weight, :integer
    add_column :users, :dog_age, :integer
    add_column :users, :address, :text
    add_column :users, :about, :text
  end
end
