class CreateEvents < ActiveRecord::Migration
  def change
    create_table :events do |t|
      t.string :event_name
      t.text :desription
      t.date :date
      t.string :location

      t.timestamps null: false
    end
  end
end
