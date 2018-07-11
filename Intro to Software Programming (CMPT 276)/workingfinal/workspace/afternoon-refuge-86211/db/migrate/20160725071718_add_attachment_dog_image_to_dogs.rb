class AddAttachmentDogImageToDogs < ActiveRecord::Migration
  def self.up
    change_table :dogs do |t|
      t.attachment :dog_image
    end
  end

  def self.down
    remove_attachment :dogs, :dog_image
  end
end
