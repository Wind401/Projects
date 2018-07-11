class CreateDogs < ActiveRecord::Migration
  def change
    create_table :dogs do |t|
      t.string :name
      t.string :breed
      t.integer :age
      t.string :gender
      t.float :weight
      t.text :about

      t.timestamps null: false
    end
  end
end
