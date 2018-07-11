class User < ActiveRecord::Base
 
  geocoded_by:address 
  after_validation :geocode, if: ->(obj){ obj.address.present? and obj.address_changed? }
  after_validation :lat_changed?
  private

# This is used to make sure that our address is actually parsed properly and we
# get a valuable lat/long
def lat_changed?
    if (self.address_changed?)
        if !(self.latitude_changed?)
            self.errors.add(:address, "is not valid")
            return false
        end
    end
    return true
end 
  
#   attr_accessible :address, :latitude, :longitude
#   geocoded_by :address
#   after_validation :geocode, :if => :address_changed?
# end
  # Include default devise modules. Others available are:
  # :confirmable, :lockable, :timeoutable and :omniauthable
  has_many :posts
  has_many :dogs, dependent: :destroy
  has_many :reviews #, dependent: :destroy

  devise :database_authenticatable, :registerable,
         :recoverable, :rememberable, :trackable, :validatable
         

  has_attached_file :image, styles: { medium: "150x150>", thumb: "50x50>" }, default_url: ":style/user.png"
  validates_attachment_content_type :image, content_type: /\Aimage\/.*\Z/
  
  acts_as_messageable

  def mailboxer_name
   self.name
  end

  def mailboxer_email(object)
   self.email
  end
  
  def self.search(search)
      where("name LIKE ?", "%#{search}%") 
  end
end#
