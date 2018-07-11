class Dog < ActiveRecord::Base
    belongs_to :user
    # Need to Change Image Size and Defult Image for Dogs
    has_attached_file :dog_image, styles: { medium: "400x320#", thumb: "200x160#" }, default_url: ":style/paw.png" #default_url: "paw.png" 
    validates_attachment_content_type :dog_image, content_type: /\Aimage\/.*\Z/
    
    validates :age, :weight, numericality: { greater_than_or_equal_to: 0,  only_integer: true }
    validates :age, numericality: { less_than_or_equal_to: 50,  only_integer: true }
end
