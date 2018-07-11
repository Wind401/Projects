class AddReferencesToReview < ActiveRecord::Migration
  def change
    add_column :reviews, :reviewer_id, :integer
    add_column :reviews, :receiver_id, :integer
    
    add_foreign_key :reviews, :users, column: :reviewer_id
    add_foreign_key :reviews, :users, column: :receiver_id
  end
end
