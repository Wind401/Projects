class Review < ActiveRecord::Base
    belongs_to :user
    
    validates :rating, numericality: { less_than_or_equal_to: 5,  only_integer: true }
end
